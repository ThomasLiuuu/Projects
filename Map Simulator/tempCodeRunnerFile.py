import pandas as pd

df_stops = pd.read_csv("grt_data/stops.txt")
df_routes = pd.read_csv("grt_data/routes.txt")
df_trips = pd.read_csv("grt_data/trips.txt")
df_stop_times = pd.read_csv("grt_data/stop_times.txt")

df_stops.head()