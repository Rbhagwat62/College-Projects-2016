
fs=16000;
tm=3;

y = wavrecord(fs*tm,fs,'double'); 
wavplay(y,fs) 
figure
title('Input Speech Signal')
plot(y)

s=removeS(y,fs);

wavplay(s,fs) 
figure
title('Speech Signal After Silence Removal')
plot(s)

[filename, pathname] = uiputfile('*.wav', 'Save as');

fp=[pathname filename];

wavwrite(s,fs,fp); 
