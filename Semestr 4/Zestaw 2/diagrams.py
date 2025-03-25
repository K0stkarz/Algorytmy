import matplotlib.pyplot as plt

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
    
    for function in functions:
        plt.figure()
        for key, values in times.items():
            if function in key:
                plt.plot(values, label=key)
        
        plt.xlabel('Test Case')
        plt.ylabel('Time (ms)')
        plt.title(f'Time Complexity of {function.capitalize()} Function')
        plt.legend()
        plt.savefig(f'/home/kostkarz/Dokumenty/Algorytmy/Semestr 4/Zestaw 2/Images/{function.capitalize()}.svg')

if __name__ == "__main__":
    file_path = '/home/kostkarz/Dokumenty/Algorytmy/Semestr 4/Zestaw 2/timesA.txt'
    times = read_times(file_path)
    plot_times(times)
