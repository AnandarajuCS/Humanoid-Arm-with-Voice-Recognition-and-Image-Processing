vid=videoinput('winvideo',1, 'YUY2_320x240');
im=getsnapshot(vid);
im=ycbcr2rgb(im);
imshow(im)