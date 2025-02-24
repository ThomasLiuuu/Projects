import pandas as pd
import json 
from sqlalchemy import create_engine

with open("./config.json", "r") as file:
    config = json.load(file)
    
