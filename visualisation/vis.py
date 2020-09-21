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
		if len(line) < 2 or (line[0] == '#' and line[1] != '#'):
			continue
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
			rooms_content[room] = []
			if start:
				rooms_content[room] = [x for x in range(1, int(ants) + 1)]
				rooms['start'] = room
				colors[room] = 'green'
				node_labels[room] = 'start'
			elif end:
				rooms['end'] = room
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


def get_point(pt1, pt2, iter):
	l = iter/(25-iter)
	x = (pt1[0] + l*pt2[0])/(1 + l)
	y = (pt1[1] + l*pt2[1])/(1 + l)
	return [x, y]

def ants_movement(iter, commands):
	x = []
	y = []
	for cmd in commands:
		pass


def print_graph(iter):
	ax.clear()
	iter -= 1
	if iter >= 0 and iter < len(commands):
		for cmd in commands[iter]:
			ant = int(cmd.split('-')[0][1:])
			room = cmd.split('-')[1]
			old_room = ant_location[ant]
			rooms_content[old_room].remove(ant)
			rooms_content[room].append(ant)
			ant_location[ant] = room
			if room != rooms['end']:
				node_labels[room] = str(ant)
				colors[room] = 'blue'
	node_labels[rooms['start']] = 'start (' + str(len(rooms_content[rooms['start']])) + ' ants)'
	node_labels[rooms['end']] = 'end (' + str(len(rooms_content[rooms['end']])) + ' ants)'
	nx.draw_networkx_nodes(G, pos, node_color=[colors[x] for x in colors.keys()], alpha=0.5, node_size=300)
	nx.draw_networkx_edges(G, pos, width=0.5, edge_color='b', alpha=0.5)
	nx.draw_networkx_labels(G, pos, labels=node_labels)
	if iter >= 0 and iter < len(commands):
		for cmd in commands[iter]:
			ant = cmd.split('-')[0][1:]
			room = cmd.split('-')[1]
			if room != rooms['end']:
				node_labels[room] = ''


ants = input()
if ants == 'ERROR':
	print(ants)
	exit(1)
fig, ax = plt.subplots(figsize=(20,12))
plt.axis('off')
G = nx.Graph()
colors = {}
node_labels = {}
commands = []
rooms = {}
rooms_content = {}
read_stdin()
ant_location = {x:rooms['start'] for x in range(1, int(ants)+1)}
pos = nx.fruchterman_reingold_layout(G)
anim = animation.FuncAnimation(fig, print_graph, frames=len(commands)+2, interval=1000, repeat=False)
plt.show()
