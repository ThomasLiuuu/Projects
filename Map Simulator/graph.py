import pandas as pd
import networkx as nx
import json 
from sqlalchemy import create_engine

with open("./config.json", "r") as file:
    config = json.load(file)
    
engine = create_engine(
    f"postgresql+psycopg2://{config['db_user']}:{config['db_password']}@{config['db_host']}:{config['db_port']}/{config['db_database']}"
)

query_stop = """
    SELECT 
"""