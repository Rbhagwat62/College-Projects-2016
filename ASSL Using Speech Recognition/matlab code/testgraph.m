fs=16000;
tm=3;

y=wavrecord(fs*tm,fs,'Double');
wavplay(y,fs);
figure;
plot(y)
title('Input Speech')

m = 100;
n = 256;
l = length(y);

nbFrame = floor((l - n) / m) + 1;

for i = 1:n
    for j = 1:nbFrame
        M(i, j) = y(((j - 1) * m) + i);
    end
end

figure;
plot(M(:,3))
title('3rd Frame Before Windowing')


h = hamming(n);

M2 = diag(h) * M;

figure;
plot(M2(:,3))
title('3rd Frame After Windowing')

for i = 1:nbFrame
    frame(:,i) = fft(M2(:, i));
end

figure;
plot(abs(frame(:,3)))
title('3rd Frame FFT')


N=n;
nofChannels=20;

df = fs/N;
Nmax = N/2;
fmax = fs/2; 
melmax = freq2mel(fmax); 
melinc = melmax / (nofChannels + 1); 
melcenters = (1:nofChannels) .* melinc;
fcenters = mel2freq(melcenters);
startfreq = [0 , fcenters(1:(nofChannels-1))];
endfreq = [fcenters(2:nofChannels) , fmax];
bandwidth = endfreq - startfreq ;
indexcenter = round(fcenters ./df);
fftfreq = indexcenter.*df;
indexstart = [1 , indexcenter(1:nofChannels-1)];
indexstop = [indexcenter(2:nofChannels),Nmax];
idxbw = (indexstop - indexstart)+1;
FFTbandwidth = idxbw.*df;
W = zeros(nofChannels,Nmax);
for c = 1:nofChannels
    %left ramp
    increment = 1.0/(indexcenter(c) - indexstart(c));
    for i = indexstart(c):indexcenter(c)
        W(c,i) = (i - indexstart(c))*increment;
    end
    %right ramp
    decrement = 1.0/(indexstop(c) - indexcenter(c));
    for i = indexcenter(c):indexstop(c)
       W(c,i) = 1.0 - ((i - indexcenter(c))*decrement);
    end
end
plot(W(1:20,1:128))
title('Mel filter')
n2 = floor(n / 2);
z = W * abs(frame(1:n2, :)).^2;

r = dct(log(z));
figure
plot(r)
title('after DCT')


 
  dirname = uigetdir('', 'Template Directory');
 
 
 
  cur_dir=cd;
  cd (dirname)
  dir_struct = dir(dirname);
  [sorted_names,sorted_index] = sortrows({dir_struct.name}');
  ind=max(sorted_index);
  cd(cur_dir) 

  for ii=3:ind
    
    fname=dir_struct(ii).name;
    tmp='\';
    fullpath=[dirname tmp fname];
    
    [y, fs] = wavread(fullpath);
    v = melfcc(y, fs);
    codebook{ii-2} = vectorq(v,16);
        
  end    
   
  distmin = inf;
  k1 = 0;
 
  for l = 1:length(codebook)      % each trained codebook, compute distortion
      d = eqdist(r, codebook{l}); 
      dist = sum(min(d,[],2)) / size(d,1);
      
      if dist < distmin
         distmin = dist;
         k1 = l;
      end      
  end

  nm=dir_struct(k1+2).name;
  
  
    l=length(nm);
    nmout=nm(1:l-4);       % skip .wav
    
    chout=[ nmout ]
    fprintf(chout)
    
  if(chout=='G')
  im=imread('G.jpg');
  figure
  imshow(im)
  title('G')
  end



