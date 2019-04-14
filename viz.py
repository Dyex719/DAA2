"""@package Visualisation
Script for Visualising the segmented lines.

Takes as input the co-ordinates of Points. This input will be from a file.
Stores the images and the GIF which helps to visualise the segmented lines.
"""
import matplotlib.pyplot as plt
import imageio
import os

points_file = "./inputs/2.txt"
results_file = "./outputs/2.txt"
save_folder = './gifs/res2/'

if not os.path.exists(save_folder):
    os.mkdir(save_folder)

with open(points_file) as o:
    orig = o.readlines()

with open(results_file) as f:
    res = f.readlines()

all_points = []
for point in orig:
    coord = point.strip().split(",")
    all_points.append({"x":int(coord[0]),"y":int(coord[1])})

quad = []
for line in res:
    res = line.strip().split()
    quad.append({"startx":int(res[0]),"starty":int(res[1]),"endx":int(res[2]),"endy":int(res[3])})

o.close()
f.close()

xs = [i["x"] for i in all_points]
ys = [i["y"] for i in all_points]

plt.scatter(xs, ys)
save_path = save_folder + '1.png'
plt.savefig(save_path)

quad = list(reversed(quad))

k=2
for j in range(len(quad)):
    if(j>0):
        s12 =(quad[j-1]["endx"], quad[j]["startx"])
        t12 =(quad[j-1]["endy"], quad[j]["starty"])
        plt.plot(s12,t12, marker = 'o')
        plt.savefig(save_folder + str(k) + ".png")
        k+=1
    x12 =(quad[j]["startx"], quad[j]["endx"])
    y12 =(quad[j]["starty"], quad[j]["endy"])
    plt.plot(x12,y12, marker = 'o')
    plt.savefig(save_folder + str(k) + ".png")
    k+=1




images = []
filenames = []
path = save_folder
for file in os.listdir(path):
    filenames.append(os.path.join(path,file))
for filename in sorted(filenames):
    images.append(imageio.imread(filename))

print(sorted(filenames))
imageio.mimsave(save_folder + 'res1.gif', images, duration=0.5)



