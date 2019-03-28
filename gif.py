import imageio
images = []
import os
filenames = []
path = "/home/addepalli/Pictures/genre/handwritten2"
for file in os.listdir(path):
    filenames.append(os.path.join(path,file))
for filename in filenames:
    images.append(imageio.imread(filename))
imageio.mimsave('test.gif', images)
