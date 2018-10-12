%octave file

clear all: 
close all; 
clc
[kk1, pathname] = uigetfile({'*.*';'*.*'},'Select a image File from image folder');     
k2=strcat(pathname,kk1);  
im = imread(k2);   
%img = imread('C:\MATLAB7\work\MF_DOF\DRIVE\test\images\01_test.tif'); 
[m n]=size(im); 
im_gray=rgb2gray(im ); 
figure,imshow(im_gray) 
[x y]=size(im_gray); 
display(x); 
display(y); 
maskForGDRange = zeros(x,y); 
mask= zeros([x y]); 
for i=1:x     
	for j=1:y             
		if   (im_gray(i,j)>10)
			mask(i,j)=255;         
		else             
			maskForGDRange(i,j) = 1;         
		end  
	end 
end
se = strel('disk',5);      
mask = imerode(mask,se);
%     im_name = strcat('E:\Computer Vision\
Copy of MatchFilter\stareimages\im',num2str(k,'%04d'),'.ppm');     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%im_name = strcat('D:\oru ami\Sem 8\
FinalYearProject_5Dec13\MF_DOF\DRIVE\test\images\',num2str(k,'%02d'),'_te st','.tif'); 
%      im_name = strcat('C:\Documents and Settings\Administrator\
My Documents\MATLAB\DRIVE\DRIVE\test\images\',num2str(k,'%02d'),'_test.tif');     
%im = imread(im_name);  
%     mask = bwselect(im2bw(im(:,:,1), 20/255), size(im(:,:,1),1)/2, size(im(:,:,1),2)/2); 
se = strel('disk',2);     
mask=imerode(mask,se);     
im = double(im(:,:,2)); 
%     man_name = strcat('E:\Computer Vision\Copy of MatchFilter\stareimages\labels-ah\im',num2str(k,'%04d'),'.ah.ppm'); %    man_name = strcat('D:\matlab_final\CBM_Bob_code\allimages\im',num2str(k,'%04d'),'.ppm');   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% man_name = strcat('C:\MATLAB7\work\MF_DOF\DRIVE\test\1st_manual\',num2str(k,'%02d'),'_ manual1.gif');    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% man = imread(man_name); 
[vess1] = MatchFilterWithGaussDerivative([],1,im,2,2,9,5,41,201,8,mask,maskForGDRange ,3,40); 
[vess2] = MatchFilterWithGaussDerivative([],2,im,1,1,9,5,21,101,8,mask,maskForGDRange ,2,40);      
vess = vess1 | vess2;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% out_name = strcat('C:\MATLAB7\work\MF_DOF\DRIVE\test\output\',num2str(k,'%02d'),'_out_ n','.gif');  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   imwrite(vess,out_name);   
%out_name = strcat('C:\MATLAB7\work\MF_DOF2\output1\',num2str(kk,'%02d'),'_out_n','.tif '); 
% imwrite(vess,out_name);     
figure,imshow(vess);          
% yd=vess1-vess2;      
%imshow(yd)       
%BW2 = edge(yd,'canny');