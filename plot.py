import matplotlib.pyplot as plt
from numpy import std, mean, sqrt
import pandas as pd
def cohen_d(x,y):
    nx = len(x)
    ny = len(y)
    dof = nx + ny - 2
    return (mean(x) - mean(y)) / sqrt(((nx-1)*std(x, ddof=1) ** 2 + (ny-1)*std(y, ddof=1) ** 2) / dof)

data = pd.read_csv('output.csv')
pd.set_option('display.float_format', lambda x: '%.0f' % x)
print(data.describe(include='all'))
print('Max First Address (s): ' + str(data["First Address"].max()/1e9))
print('Max Last Address  (s): ' + str(data["Last Address"].max()/1e9))

d = cohen_d(data["First Address"].to_numpy(), data['Last Address'].to_numpy())
print('Cohen\'s d: ' + str(d))
data.hist(bins=100)
plt.show()