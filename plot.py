import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('./cost.csv')
data.plot(x='iterations', y='cost')
plt.xlim(0, 99999)  # Set x-axis limits from 0 to 10
plt.ylim(0, 0.2)  # Set y-axis limits from 0 to 10
plt.grid(True)  # Turn on the grid lines
plt.show()
