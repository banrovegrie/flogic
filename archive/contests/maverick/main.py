import pandas as pd
bid_ask = pd.read_csv("Bid_ask.csv")
trades = pd.read_csv("Trades.csv")

def convert_timestamp_to_seconds(time):
    lst = list(map(int, time[-9:].split(':')))
    return lst[0] * 3600 + lst[1] * 60 + lst[2]

def delta_quality(x: int):
    total_vol = 0
    num = 0
    for time, side, vol, price in zip(trades["timestamp_gmt"], trades["side"], trades["volume"], trades["price"]):
        t = convert_timestamp_to_seconds(time)
        total_vol += vol
        
        ptx = 0
        for ts, p in zip(bid_ask["timestamp_gmt"], bid_ask["ask"]):
            i = convert_timestamp_to_seconds(ts)
            if i >= t + x:
                ptx = p
                break
        st = 1 if side == "BOT" else 0
        num += ((ptx - price) / price) * st * vol

    num /= total_vol
    num *= 100
    print(f"{num}%")
    return num

delta_quality(10)
delta_quality(60)