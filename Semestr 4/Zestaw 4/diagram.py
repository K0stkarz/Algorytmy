import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Ustaw backend bez GUI
import matplotlib
matplotlib.use('Agg')

df = pd.read_csv("data.csv")

# Oblicz teoretyczną O(n²) na podstawie pierwszego punktu
n_ref = df["vertex_count"].iloc[0]
t_ref = df["time_ms"].iloc[0]
C = t_ref / (n_ref ** 2)  # Stała proporcjonalności

# Generuj teoretyczne wartości
df["time_theory"] = C * df["vertex_count"] ** 2

# Wykres
plt.figure(figsize=(10, 6))
plt.plot(df["vertex_count"], df["time_ms"], "o-", label="Czas rzeczywisty")
plt.plot(df["vertex_count"], df["time_theory"], "--", label="Teoretyczna O(n²)")
plt.xlabel("Liczba wierzchołków (n)")
plt.ylabel("Czas wykonania (ms)")
plt.title("Złożoność removeVertex (test z większymi n)")
plt.legend()
plt.grid(True)
plt.savefig("Images/wykres.svg")