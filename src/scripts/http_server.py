import os

from flask import Flask, send_file, jsonify, after_this_request
from zipfile import ZipFile

app = Flask(__name__)


@app.route('/get_images', methods=['POST'])
def get_images():
    image_folder = '/home/x650/Multitask-Drone/src/drone_vision/images/task_clean/raw'
    images = os.listdir(image_folder)  
    image_paths = [os.path.join(image_folder, img) for img in images if img.endswith(('.png', '.jpg', '.jpeg'))]

    if not image_paths:
        return jsonify({"message": "No images found"}), 404

    zip_path = "/tmp/raw.zip"
    with ZipFile(zip_path, 'w') as zipf:
        for img in image_paths:
            zipf.write(img, os.path.basename(img))
    
    @after_this_request
    def remove_file(response):
        try:
            os.remove(zip_path)
        except Exception as e:
            print(e)
        return response

    return send_file(zip_path, as_attachment=True)


@app.route('/get_json', methods=['POST'])
def get_json():
    json_path = '/home/x650/Multitask-Drone/src/json_paths/path.json'
    
    if not os.path.exists(json_path):
        return jsonify({"message": "JSON file not found"}), 404

    if not os.path.exists(json_path):
        return jsonify({"message": "JSON file not found"}), 404

    return send_file(json_path, as_attachment=True)

if __name__ == '__main__':
    try:
        app.run(host='0.0.0.0', port=5000) 
    except Exception as e:
        print(e)