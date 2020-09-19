import subprocess




for _ in range(100):
	check = subprocess.Popen(['./lem-in'], stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
	with open ('/Users/admin/school_21/lemin_v2/test_maps/20.map', 'rb') as r:
		ll = b''.join(r.readlines())
		check.communicate(input = ll)[0]
	l = str(check.communicate()[0])
	if 'ERROR' in l:
		print (str(l))

