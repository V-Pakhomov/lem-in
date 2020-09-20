import os
import random
import subprocess

input = open("/Users/admin/school_21/lemin_v2/test_maps/20.map").readlines()

res = subprocess.run(['/Users/admin/school_21/lemin_v2/lem-in'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
print('ok')
