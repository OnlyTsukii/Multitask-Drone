import json

from drone_interfaces.msg import Task, RawWaypoint
from drone_controller.utils import *
from geopy.distance import geodesic


class WaypointParseException(Exception):
    pass

class TaskHandler():
    def __init__(self):
        pass

    def parse_waypoint(self, raw_waypoint) -> RawWaypoint:
        try:
            parsed_wp = raw_waypoint
            if not isinstance(raw_waypoint, dict):
                parsed_wp = json.loads(raw_waypoint)
        except json.JSONDecodeError as e:
            raise WaypointParseException("Failed to parse JSON data") from e

        # Check 'type' field
        type = parsed_wp.get('type')
        if type is None:
            raise WaypointParseException("Missing 'type' field")
        elif not is_valid_type(type):
            raise WaypointParseException(f"Invalid 'type' value: {type}")

        # Check 'mission' field
        mission = parsed_wp.get('mission')
        if mission is None:
            raise WaypointParseException("Missing 'mission' field")
        elif not is_valid_mission(mission):
            raise WaypointParseException(f"Invalid 'mission' value: {mission}")
        
        # Check 'velocity' field
        velocity = parsed_wp.get('velocity')
        if velocity is None:
            raise WaypointParseException("Missing 'velocity' field")
        elif not is_valid_velocity(velocity):
            raise WaypointParseException(f"Invalid 'velocity' value: {velocity}")

        # Check 'latitude' field
        latitude = parsed_wp.get('latitude')
        if latitude is None:
            raise WaypointParseException("Missing 'latitude' field")
        elif not is_valid_latitude(latitude):
            raise WaypointParseException(f"Invalid 'latitude' value: {latitude}")

        # Check 'longitude' field
        longitude = parsed_wp.get('longitude')
        if longitude is None:
            raise WaypointParseException("Missing 'longitude' field")
        elif not is_valid_longitude(longitude):
            raise WaypointParseException(f"Invalid 'longitude' value: {longitude}")

        # Check 'altitude' field
        altitude = parsed_wp.get('altitude')
        if altitude is None:
            raise WaypointParseException("Missing 'altitude' field")
        elif not is_valid_altitude(altitude):
            raise WaypointParseException(f"Invalid 'altitude' value: {altitude}")

        waypoint = RawWaypoint()
        waypoint.type = type
        waypoint.mission = mission
        waypoint.latitude = float(latitude)
        waypoint.longitude = float(longitude)
        waypoint.altitude = float(altitude)
        waypoint.velocity = float(velocity)

        return waypoint

    def parse_task(self, raw_task) -> Task:
        waypoints = []
        for raw_wp in raw_task:
            try:
                parsed_waypoint = self.parse_waypoint(raw_wp)
                if parsed_waypoint:
                    waypoints.append(parsed_waypoint)
            except WaypointParseException as e:
                raise e
            
        task = Task()
        task.waypoints = waypoints

        return task
    

    def interpolate_waypoints(self, waypoints):
        if len(waypoints) < 2:
            return waypoints
        
        interpolated = [waypoints[0]]
        
        for i in range(1, len(waypoints)):
            prev = waypoints[i-1]
            curr = waypoints[i]

            if prev.mission != MISSION_LOCAL_CAPTURE or curr.mission != MISSION_LOCAL_CAPTURE:
                interpolated.append(curr)
                continue
            
            altitude = prev.altitude
            
            distance_meters = geodesic(
                (prev.latitude, prev.longitude),
                (curr.latitude, curr.longitude)
            ).meters
            
            segment_distance = altitude / 4
            
            if distance_meters <= segment_distance:
                interpolated.append(curr)
                continue
                
            num_segments = math.ceil(distance_meters / segment_distance)
            
            for j in range(1, num_segments):
                ratio = j / num_segments
                
                new_wp = RawWaypoint()
                new_wp.type = prev.type
                new_wp.mission = prev.mission
                new_wp.velocity = prev.velocity
                
                new_wp.latitude = prev.latitude + ratio * (curr.latitude - prev.latitude)
                new_wp.longitude = prev.longitude + ratio * (curr.longitude - prev.longitude)
                new_wp.altitude = prev.altitude
                
                interpolated.append(new_wp)
            
            interpolated.append(curr)
        
        return interpolated
            
    def validate_task(self, task: Task) -> bool:
        if len(task.waypoints) == 0:
            return False

        for i in range(len(task.waypoints) - 1):
            res = is_valid_distance(task.waypoints[i], task.waypoints[i + 1])

            if not res:
                return False

        return True

    def handle_json_data(self, json_data):
        """
        Handle incoming JSON data:
        1. Parse the task.
        2. Validate the task.
        3. Generate new waypoints.
        """
        try:
            # Parse the task
            raw_task = json_data
            if not isinstance(json_data, (dict, list)):
                raw_task = json.loads(json_data)
        
            task = self.parse_task(raw_task)
            if not task:
               return None, {"status": "error", "message": "Invalid task format"}
            
            # Validate the task
            if not self.validate_task(task):
                return None, {"status": "error", "message": "Task validation failed"}
            
            # Generate new waypoints
            task.waypoints = self.interpolate_waypoints(task.waypoints)
            
            return task, None
        
        except json.JSONDecodeError:
            return None, {"status": "error", "message": "Invalid JSON format"}
        except Exception as e:
            return None, {"status": "error", "message": f"An unexpected error occurred: {str(e)}"}