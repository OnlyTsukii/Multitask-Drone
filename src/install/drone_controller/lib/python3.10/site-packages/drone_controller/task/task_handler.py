import json

from drone_interfaces.msg import Task, RawWaypoint
from drone_controller.utils import *


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
            
    def validate_task(self, task: Task) -> bool:
        # If there is only one or no waypoint, return True (valid task)
        if len(task.waypoints) == 0:
            return False

        # Iterate through consecutive waypoints
        for i in range(len(task.waypoints) - 1):
            res = is_valid_distance(task.waypoints[i], task.waypoints[i + 1])

            if not res:
                return False

        # Return True if all distances are within the limit
        return True

    def handle_json_data(self, json_data, socket):
        """
        Handle incoming JSON data:
        1. Parse the task.
        2. Validate the task.
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
            
            return task, None
        
        except json.JSONDecodeError:
            return None, {"status": "error", "message": "Invalid JSON format"}
        except Exception as e:
            return None, {"status": "error", "message": f"An unexpected error occurred: {str(e)}"}