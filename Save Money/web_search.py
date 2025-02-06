import os 
import requests
from serpapi import GoogleSearch

# api key for google search
serpapi_key = "e71cb757d7b42f5fc0575f396a99cce1e33c8abf708fc0b57e0925921e10dbca"

# search on Google
def google_search(query): 
    search = GoogleSearch({
        "q": query,
        "hl": "en",
        "gl": "ca",
        "location": "Toronto, Ontario, Canada",
        "api_key": serpapi_key
    })
    
    result = search.get_dict()
    search_result = result.get("organic_results", [])
    
    if not search_result:
        print("No result found")
        return None 

    product = search_result[0]
    title = product.get("title", "Not found")
    price = product.get("price", "Not found")
    link = product.get("link", "#")
    
    return {
        "title": title,
        "price": price,
        "link": link
    }

# search for Bank of Canada interest rate 
def get_interest_rate():
    url = "https://www.bankofcanada.ca/valet/observations/V39079/json"
    
    response = requests.get(url)
    if response.status_code != 200:
        print("Failed to fetch data from the Bank of Canada API.")
        return None
    
    data = response.json()
    
    # Extract the latest observation
    observations = data.get("observations", [])
    if not observations:
        print("No interest rate data available.")
        return None
    
    latest_rate = observations[-1]  # Get the most recent rate
    date = latest_rate["d"]
    rate = latest_rate["V39079"]["v"]

    return date, rate