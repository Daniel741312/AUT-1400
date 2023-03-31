import os
import matplotlib.image as mpimg
from PIL import Image
import matplotlib.pyplot as plt
import matplotlib as mpl

# while, I'm not instrested in pyplot
img = mpimg.imread(r"../resources/image.jpg")
fig = plt.figure()
ax1 = fig.add_subplot()
ax1.imshow(img)
ax1.axis("off")
plt.show()