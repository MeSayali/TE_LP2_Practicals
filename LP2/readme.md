Expert System - Stock Market
```
def expert_system(price, moving_avg, rsi, trend, volume):
    buy_score = 0
    sell_score = 0
    explanation = []

    # RSI rules
    if rsi < 30:
        buy_score += 2
        explanation.append("RSI indicates oversold condition (BUY)")
    elif rsi > 70:
        sell_score += 2
        explanation.append("RSI indicates overbought condition (SELL)")

    # Moving Average rules
    if price > moving_avg:
        buy_score += 1
        explanation.append("Price is above Moving Average (BUY)")
    else:
        sell_score += 1
        explanation.append("Price is below Moving Average (SELL)")

    # Trend rules
    if trend.lower() == "up":
        buy_score += 1
        explanation.append("Market trend is upward (BUY)")
    elif trend.lower() == "down":
        sell_score += 1
        explanation.append("Market trend is downward (SELL)")

    # Volume rule
    if volume.lower() == "high":
        explanation.append("High volume strengthens the signal")

    # Decision
    if buy_score > sell_score:
        decision = "BUY"
    elif sell_score > buy_score:
        decision = "SELL"
    else:
        decision = "HOLD"

    confidence = abs(buy_score - sell_score) * 20  # simple %

    return decision, confidence, explanation


def main():
    while True:
        print("\n===== STOCK EXPERT SYSTEM =====")
        print("1. Analyze Stock")
        print("2. View Rules")
        print("3. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            price = float(input("Enter current price: "))
            moving_avg = float(input("Enter moving average: "))
            rsi = float(input("Enter RSI: "))
            trend = input("Enter trend (up/down): ")
            volume = input("Enter volume (high/low): ")

            decision, confidence, explanation = expert_system(
                price, moving_avg, rsi, trend, volume
            )

            print("\n===== RESULT =====")
            print("Decision:", decision)
            print("Confidence:", confidence, "%")

            print("\nReasoning:")
            for e in explanation:
                print("-", e)

        elif choice == "2":
            print("\n===== RULES =====")
            print("RSI < 30 → BUY (Oversold)")
            print("RSI > 70 → SELL (Overbought)")
            print("Price > Moving Avg → BUY")
            print("Price < Moving Avg → SELL")
            print("Trend Up → BUY")
            print("Trend Down → SELL")
            print("High Volume → Stronger Signal")

        elif choice == "3":
            print("Exiting system...")
            break

        else:
            print("Invalid choice! Try again.")


main()
```

