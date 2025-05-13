import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression  # Nowy import

# Ustaw backend bez GUI
import matplotlib
matplotlib.use('Agg')

# Wczytaj dane
df = pd.read_csv("data.csv")

# Dopasowanie modelu Y = C * X (bez wyrazu wolnego)
x = df["vertex_count"].values.reshape(-1, 1)
y = df["time_ms"].values.reshape(-1, 1)

model = LinearRegression(fit_intercept=False)  # Kluczowa zmiana!
model.fit(x, y)
C = model.coef_[0][0]  # Współczynnik C

# Generuj teoretyczne wartości
df["time_theory"] = C * df["vertex_count"]

# Wykres
plt.figure(figsize=(12, 7))
plt.plot(df["vertex_count"], df["time_ms"], "o-", label="Czas rzeczywisty", markersize=8)
plt.plot(df["vertex_count"], df["time_theory"], "--", 
         label=f"Teoretyczna O(n)", linewidth=2, color="orange")

plt.xlabel("Liczba wierzchołków (n)", fontsize=12)
plt.ylabel("Czas wykonania (ms)", fontsize=12)
plt.title("Złożoność removeVertex dla listy sąsiedztwa", fontsize=14)
plt.legend(fontsize=12, loc="upper left")
plt.grid(True, linestyle="--", alpha=0.7)

# Formatowanie osi
plt.xticks(np.arange(0, 110000, 10000), rotation=45)
plt.xlim(0, 105000)  # Wymuszenie rozpoczęcia osi X od zera
plt.ylim(0, 25)       # Dopasowanie osi Y

plt.tight_layout()
plt.savefig("Images/wykres.svg")