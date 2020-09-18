#!/usr/bin/python

import sys
import networkx as nx
import matplotlib.pyplot as plt

def is_room(line):
	line = line.split()
	if len(line) != 3:
		return False
	try:
		x = int(line[1])
		y = int(line[2])
		return True
	except Exception:
		return False

def is_link(line):
	if line[0] == '#' or line[0] == 'L':
		return False
	return len(line.split('-')) == 2

ants = input()
if ants == 'Error\n':
	print(ants)
	exit(1)
plt.figure()
G = nx.Graph()
vertices = 0
start = False
end = False
colors = {}
edge_labels = {}
for line in sys.stdin:
	if line == '##start\n' or line == '##end\n':
		start = (line == '##start\n')
		end = (line == '##end\n')
		continue
	if is_room(line):
		vertices += 1
		if vertices > 1010:
			print('To many vertices')
			exit(1)
		room = line.split()[0]
		if start:
			colors[room] = 'green'
		elif end:
			colors[room] = 'red'
		else:
			colors[room] = 'black'
		G.add_node(room)
		start = False
		end = False
	elif is_link(line):
		room1 = line.split('-')[0]
		room2 = line.split('-')[1][:-1]
		G.add_edge(room1, room2)
		edge_labels[(room1, room2)] = room1 + '-' + room2
pos = nx.kamada_kawai_layout(G)
for node in G.nodes():
	nx.draw_networkx_nodes(G, pos, [node], node_color=colors[node], node_size=100)
nx.draw_networkx_edges(G, pos, width=0.5, edge_color='b', alpha=0.5)
plt.axis('off')
plt.show()

