import matplotlib.pyplot as plt
import os

def read_times(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    
    times = {}
    current_key = None
    
    for line in lines:
        if line.strip() == "":
            continue
        if not line[0].isdigit():
            current_key = line.strip()
            times[current_key] = []
        else:
            times[current_key].append(int(line.split()[1]))
    
    return times

def plot_times(times):
    functions = set(key.split()[1] for key in times.keys())
    output_dir = '/home/kostkarz/Dokumenty/Algorytmy/Semestr 4/Zestaw 3/Images/'
    os.makedirs(output_dir, exist_ok=True)
    
    x = [0, 9]
    y = [0, 200]

    x_1 = [0, 9]
    y_1 = [0, 0]

    for function in functions:
        plt.figure()
        for key, values in times.items():
            if function in key:
                plt.plot(values, label=key)
                
        plt.plot(x, y, 'k--', label='O(n)', color='#2c1d42')
        plt.plot(x_1, y_1, 'k--', label='O(1)', color='#750027')
        plt.xlabel('Test Case')
        plt.ylabel('Time (ms)')
        plt.title(f'Time Complexity of {function.capitalize()} Function')
        plt.legend()
        plt.savefig(f'/home/kostkarz/Dokumenty/Algorytmy/Semestr 4/Zestaw 3/Images/{function.capitalize()}.svg')

if __name__ == "__main__":
    file_path = '/home/kostkarz/Dokumenty/Algorytmy/Semestr 4/Zestaw 3/times.txt'
    times = read_times(file_path)
    plot_times(times)
