import matplotlib.pyplot as plt
import imageio
import os
points_file = "./inputs/2.txt"
results_file = "./outputs/2g.txt"
save_folder = './gifs/res2/'

with open(points_file) as o:
    orig = o.readlines()

with open(results_file) as f:
    res = f.readlines()

all_points = []
for point in orig:
    coord = point.strip().split(',')
    all_points.append({"x":int(coord[0]),"y":int(coord[1])})

points = []
for point in res:
    coord = point.strip().split(',')
    points.append({"x":int(coord[0]),"y":int(coord[1])})

o.close()
f.close()

xs = [i["x"] for i in all_points]
ys = [i["y"] for i in all_points]

plt.scatter(xs, ys)
save_path = save_folder + '1.png'
plt.savefig(save_path)

xh = [i["x"] for i in points]
yh = [i["y"] for i in points]
xh.append(xh[0])
yh.append(yh[0])

for j in range(len(xh)-1):
    x12 =(xh[j], xh[j+1])
    y12 = (yh[j], yh[j+1])
    plt.plot(x12,y12, marker = 'o')
    plt.savefig(save_folder + str(j+2) + ".png")

images = []
filenames = []
path = save_folder
for file in os.listdir(path):
    filenames.append(os.path.join(path,file))
for filename in sorted(filenames):
    images.append(imageio.imread(filename))
imageio.mimsave(save_folder + 'res1.gif', images, duration=0.5)
