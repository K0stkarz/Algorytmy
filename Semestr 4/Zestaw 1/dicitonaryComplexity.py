import matplotlib.pyplot as plt

def read_data(file_path):
    data = {}
    with open(file_path, 'r') as file:
        lines = file.readlines()
        current_key = None
        for line in lines:
            if line.startswith('dictionary'):
                current_key = line.strip()
                data[current_key] = {'x': [], 'y': []}
            else:
                x, y = map(int, line.split())
                data[current_key]['x'].append(x)
                data[current_key]['y'].append(y)
    return data

def plot_data(data):
    for key, values in data.items():
        plt.plot(values['x'], values['y'], label=key)
    plt.xlabel('Operation Count')
    plt.ylabel('Time (ms)')
    plt.title('Dictionary Operations Complexity')
    plt.legend()
    plt.show()

if __name__ == "__main__":
    file_path = 'c:\\Users\\Kostkarz\\Desktop\\Algorytmy\\Semestr 4\\Zestaw 1\\timesDictionary,txt'
    data = read_data(file_path)
    plot_data(data)
