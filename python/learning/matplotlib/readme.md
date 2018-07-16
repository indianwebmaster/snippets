- https://www.datacamp.com/community/tutorials/matplotlib-tutorial-python

> Image Components

![Image Components](components.png)

1. The Figure is the overall window or page that everything is drawn on. It’s the 
top-level component.
1. To the figure you add Axes. The Axes is the area on which the data is plotted 
with functions such as plot() and scatter() and that can have ticks, labels, 
etc. associated with it.
1. All methods of an Axes object exist as a function in the pyplot module and vice versa.
Thus, if you see `plt.xlim()`, its actually calling `ax.set_xlim()` behind the covers.
Mostly, you’ll use the functions of the pyplot module because they’re much cleaner, 
at least for simple plots, however make a habit of using the Axes object to follow proper guidelines.
1. Each Axes has the x-axis and y-axis, along with 
- major and minor tick lines and tick labels
- axis labels, titles and legend
- axis scales and gridlines
- The axis lines are termed as "spines". The top & right spines are set to invisible.

> Data
1. You can pass Python lists or numpy arrays to the plotting functions. Basically any iterable can
be passed. However, you cannot include generator functions (see learning/yield_iterables_generators)

> Basic Implementation
