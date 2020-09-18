#!/usr/bin/python

import sys
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as animation


def read_stdin():
	vertices = 0
	start = False
	end = False
	for line in sys.stdin:
		if line[-1] == '\n':
			line = line[:-1]
		if line == '##start' or line == '##end':
			start = (line == '##start')
			end = (line == '##end')
			continue
		if is_room(line):
			vertices += 1
			if vertices > 1010:
				print('To many vertices')
				exit(1)
			room = line.split()[0]
			if start:
				colors[room] = 'green'
				node_labels[room] = 'start'
			elif end:
				node_labels[room] = 'end'
				colors[room] = 'red'
			else:
				node_labels[room] = ''
				colors[room] = 'grey'
			G.add_node(room)
			start = False
			end = False
		elif is_link(line):
			room1 = line.split('-')[0]
			room2 = line.split('-')[1]
			G.add_edge(room1, room2)
		elif line[0] == 'L':
			commands.append(line.split())


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


def print_graph():
	pos = nx.kamada_kawai_layout(G)
	for node in G.nodes():
		nx.draw_networkx_nodes(G, pos, [node], node_color=colors[node], alpha=0.5, node_size=300)
	nx.draw_networkx_edges(G, pos, width=0.5, edge_color='b', alpha=0.5)
	nx.draw_networkx_labels(G, pos, labels=node_labels)
	plt.axis('off')
	plt.show()


def refresh_graph(G, colors, labels, commands):
	pos = nx.kamada_kawai_layout(G)
	for com in commands:
		ant = com.split('-')[0][1:]
		room = com.split('-')[1]
		labels[room] = str(ant)
		colors[room] = 'blue'
	nx.relabel_nodes(G, labels)
	plt.axis('off')
	plt.show()


def update(iter):
	pass
	

ants = input()
if ants == 'ERROR':
	print(ants)
	exit(1)
fig = plt.figure(figsize=(20,12))
G = nx.Graph()
colors = {}
node_labels = {}
commands = []
read_stdin()
# anim = animation.FuncAnimation(fig, update, frames=len(commands)+2, interval=1000, repeat=False)
# plt.show()
print_graph()
#refresh_graph(G, colors, node_labels, ['L1-14', 'L2-0', 'L3-2', 'L4-1'])
