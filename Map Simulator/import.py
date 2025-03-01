import pandas as pd
import json 
from sqlalchemy import create_engine

with open("./config.json", "r") as file:
    config = json.load(file)
    
engine = create_engine(
    f"postgresql+psycopg2://{config['db_user']}:{config['db_password']}@{config['db_host']}:{config['db_port']}/{config['db_database']}"
)

grt_files = {
    'stops.txt': 'stops',
    'routes.txt': 'routes',
    'trips.txt': 'trips',
    'stop_times.txt': 'stop_times'
}

grt_folder = './grt_data/'

for file, table in grt_files.items():
    print(f"Importing {file} into {table}")
    file_path = grt_folder + file
    
    try: 
        df = pd.read_csv(file_path)
        
        df.columns = df.columns.str.lower().str.strip()
        
        df.to_sql(table, engine, if_exists='replace', index=False)
        
        print(f"Imported {file} into {table}")
    
    except Exception as e:
        print(f"Failed to import {file} into {table}")
        print(e)
        