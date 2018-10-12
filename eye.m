#matlab file


t=('image.jpg');  
i=imread(t);  
figure, imshow(i)  
q=rgb2hsv(i);  
t=rgb2gray(i);  
figure, imshow(t)  
k=medfilt2(t);  
figure, imshow(k)  
u=adapthisteq(k);  
se=strel('disk',10);  
c=imclose(u,se);  
figure, imshow(c)  
d=imfill(u,'holes');  
figure, imshow(d)  
z=imabsdiff(c,d);  
figure, imshow(z)  
level=graythresh(z);  
BW=im2bw(z,level);  
imshow(BW)