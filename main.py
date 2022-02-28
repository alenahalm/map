import matplotlib.pyplot as plt

file = open('out.txt', 'r')
time = []
for i in file:
    str = i[0:-1:]
    if str == 'TIME:':
        continue
    if str == '':
        break
    pair = (int(str.split()[0]), float(str.split()[1]))
    data = (pair[0], pair[1])
    time.append(data)

x = []
y = []
for p in time:
    x.append(p[0])
    y.append(p[1])

plt.plot(x, y)
plt.xlabel('Number of elements')
plt.ylabel('Time in ms')

plt.title('Time for map')
plt.show()

memory = []

for i in file:
    str = i[0:-1:]
    if str == 'MEMORY:':
        continue
    pair = (int(str.split()[0]), int(str.split()[1]))
    data = (pair[0], pair[1])
    memory.append(data)

x = []
y = []
for p in memory:
    x.append(p[0])
    y.append(p[1])
plt.plot(x, y)
plt.xlabel('Number of elements')
plt.ylabel('Memory')

plt.title('Memory for map')
plt.show()
print(x)
print(y)