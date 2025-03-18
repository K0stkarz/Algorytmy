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
        plt.show()

if __name__ == "__main__":
    file_path = 'c:\\Users\\Kostkarz\\Desktop\\Algorytmy\\Semestr 4\\Zestaw 1\\times.txt'
    times = read_times(file_path)
    plot_times(times)
