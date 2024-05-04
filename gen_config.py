import yaml
import random
import string

try:
    from yaml import CLoader as Loader, CDumper as Dumper
except ImportError:
    from yaml import Loader, Dump


b = {}
for i in range(0,100000):
    key = 'build_' + str(i+1)
    res = ''.join(random.choices(string.ascii_uppercase +
                             string.digits, k=50))
    
    b[key] = {'Description':res, 'Address': i, 'Default_Value': random.getrandbits(32)}
with open('config.yaml','w') as f:
    yaml.dump(b,f,Dumper=Dumper,sort_keys=False)
