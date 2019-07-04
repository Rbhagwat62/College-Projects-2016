
fs=16000;
tm=3;

y=wavrecord(fs*tm,fs,'Double');
wavplay(y,fs);
figure;
plot(y)

s=removeS(y,fs);
wavplay(s,fs);
figure;
plot(s)

q=input(' YES =1 NO=0   ');

if q==1
    
   vin = melfcc(s,fs);   
 
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
      d = eqdist(vin, codebook{l}); 
      dist = sum(min(d,[],2)) / size(d,1);
      
      if dist < distmin
         distmin = dist;
         k1 = l;
      end      
  end

    nm=dir_struct(k1+2).name;
  
  
    l=length(nm);
    nmout=nm(1:l-4);       % skip .wav
    
    
    comp = serial('COM3');
    set(comp,'BaudRate',9600);
    fopen(comp);
    
    
    chout=['*' nmout '$']
    fprintf(comp,chout)
    
    fclose(comp)
    delete(comp)
    clear comp
    
  if(chout=='G')
  im=imread('G.jpg');
  figure
  imshow(im)
  end
  if(chout=='A')
  im=imread('A.jpg');
  figure
  imshow(im)
  end
  
end
