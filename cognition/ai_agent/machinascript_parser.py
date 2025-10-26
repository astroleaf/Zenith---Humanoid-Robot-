import json

class MachinaScriptParser:
    def __init__(self):
        pass

    def parse(self, script_json):
        actions = json.loads(script_json)
        return actions

    def execute(self, actions, skills):
        for action in actions.get('actions', []):
            skill_name = action.get('skill')
            params = action.get('params', {})
            if skill_name in skills:
                skills[skill_name](**params)
            else:
                print(f"Unknown skill: {skill_name}")
