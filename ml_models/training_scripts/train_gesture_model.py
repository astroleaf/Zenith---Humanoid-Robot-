import tensorflow as tf
from tensorflow.keras import layers, models
from tensorflow.keras.preprocessing.image import ImageDataGenerator

def train_gesture_model(data_dir, model_output):
    datagen = ImageDataGenerator(rescale=1./255, validation_split=0.2)
    train_gen = datagen.flow_from_directory(data_dir, target_size=(64,64), batch_size=32, subset='training')
    val_gen = datagen.flow_from_directory(data_dir, target_size=(64,64), batch_size=32, subset='validation')

    model = models.Sequential([
        layers.Conv2D(32, (3,3), activation='relu', input_shape=(64,64,3)),
        layers.MaxPooling2D(),
        layers.Conv2D(64, (3,3), activation='relu'),
        layers.MaxPooling2D(),
        layers.Flatten(),
        layers.Dense(64, activation='relu'),
        layers.Dense(train_gen.num_classes, activation='softmax')
    ])

    model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
    model.fit(train_gen, validation_data=val_gen, epochs=10)
    model.save(model_output)
    print(f"Model saved to {model_output}")

if __name__ == "__main__":
    train_gesture_model('gesture_data/', 'gesture_model.h5')
