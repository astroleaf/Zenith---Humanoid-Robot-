import cv2
import os

def preprocess_images(input_dir, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    for filename in os.listdir(input_dir):
        if filename.endswith(".jpg") or filename.endswith(".png"):
            img = cv2.imread(os.path.join(input_dir, filename))
            resized = cv2.resize(img, (64, 64))
            cv2.imwrite(os.path.join(output_dir, filename), resized)

if __name__ == "__main__":
    preprocess_images('raw_images', 'processed_images')
