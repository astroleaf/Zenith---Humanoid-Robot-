
import os
from inference import TFLiteModel

class ModelLoader:
    def __init__(self, models_dir="ml_models"):
        self.models_dir = models_dir
        self.models = {}

    def load_model(self, model_name):
        model_path = os.path.join(self.models_dir, model_name)
        self.models[model_name] = TFLiteModel(model_path)
        print(f"Loaded model {model_name}")

    def infer(self, model_name, input_data):
        if model_name not in self.models:
            raise ValueError(f"Model {model_name} not loaded")
        return self.models[model_name].infer(input_data)
