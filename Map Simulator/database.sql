CREATE TABLE agencies (
    agency_id TEXT PRIMARY KEY,
    agency_name TEXT NOT NULL,
    agency_url TEXT NOT NULL,
    agency_timezone TEXT NOT NULL,
    agency_lang TEXT,
    agency_phone TEXT,
    agency_fare_url TEXT
);

CREATE TABLE stops (
    stop_id TEXT PRIMARY KEY,
    stop_name TEXT NOT NULL,
    stop_desc TEXT,
    stop_lat DOUBLE PRECISION NOT NULL,
    stop_lon DOUBLE PRECISION NOT NULL,
    zone_id TEXT,
    stop_url TEXT,
    location_type INTEGER,
    parent_station TEXT,
    wheelchair_boarding INTEGER
);

CREATE TABLE routes (
    route_id TEXT PRIMARY KEY,
    agency_id TEXT,
    route_short_name TEXT,
    route_long_name TEXT,
    route_desc TEXT,
    route_type INTEGER NOT NULL,
    route_url TEXT,
    route_color TEXT,
    route_text_color TEXT,
    FOREIGN KEY (agency_id) REFERENCES agencies(agency_id)
);

CREATE TABLE trips (
    route_id TEXT,
    service_id TEXT,
    trip_id TEXT PRIMARY KEY,
    trip_headsign TEXT,
    trip_short_name TEXT,
    direction_id INTEGER,
    block_id TEXT,
    shape_id TEXT,
    wheelchair_accessible INTEGER,
    bikes_allowed INTEGER,
    FOREIGN KEY (route_id) REFERENCES routes(route_id)
);

CREATE TABLE stop_times (
    trip_id TEXT,
    arrival_time TEXT,
    departure_time TEXT,
    stop_id TEXT,
    stop_sequence INTEGER,
    stop_headsign TEXT,
    pickup_type INTEGER,
    drop_off_type INTEGER,
    shape_dist_traveled DOUBLE PRECISION,
    timepoint INTEGER,
    PRIMARY KEY (trip_id, stop_sequence),
    FOREIGN KEY (trip_id) REFERENCES trips(trip_id),
    FOREIGN KEY (stop_id) REFERENCES stops(stop_id)
);

CREATE TABLE calendar (
    service_id TEXT PRIMARY KEY,
    monday BOOLEAN,
    tuesday BOOLEAN,
    wednesday BOOLEAN,
    thursday BOOLEAN,
    friday BOOLEAN,
    saturday BOOLEAN,
    sunday BOOLEAN,
    start_date DATE,
    end_date DATE
);

CREATE TABLE calendar_dates (
    service_id TEXT,
    date DATE,
    exception_type INTEGER,
    PRIMARY KEY (service_id, date),
    FOREIGN KEY (service_id) REFERENCES calendar(service_id)
);

CREATE INDEX idx_stop_id ON stops (stop_id);
CREATE INDEX idx_stop_lat_lon ON stops USING btree (stop_lat, stop_lon);

CREATE INDEX idx_route_id ON routes (route_id);

CREATE INDEX idx_trip_id ON trips (trip_id);
CREATE INDEX idx_route_service_id ON trips (route_id, service_id);

CREATE INDEX idx_trip_stop_sequence ON stop_times (trip_id, stop_sequence);
CREATE INDEX idx_stop_id_arrival_time ON stop_times (stop_id, arrival_time);

CREATE INDEX idx_service_id ON calendar (service_id);

CREATE INDEX idx_service_date ON calendar_dates (service_id, date);



