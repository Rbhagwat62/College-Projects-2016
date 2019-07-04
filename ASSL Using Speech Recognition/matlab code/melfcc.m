function r = melfcc(y, fs)

m = 100;
n = 256;
l = length(y);

nbFrame = floor((l - n) / m) + 1;

for i = 1:n
    for j = 1:nbFrame
        M(i, j) = y(((j - 1) * m) + i);
    end
end

h = hamming(n);

M2 = diag(h) * M;

for i = 1:nbFrame
    frame(:,i) = fft(M2(:, i));
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
N=n;
nofChannels=20;

df = fs/N; %frequency increment on linear scale
Nmax = N/2; % maximum fft index
fmax = fs/2; % maximum frequency
melmax = freq2mel(fmax); % maximum mel frequency
melinc = melmax / (nofChannels + 1); % frequency increment on mel scale

%center frequencies on mel scale
melcenters = (1:nofChannels) .* melinc;

%center frequencies in linear scale [Hz]
fcenters = mel2freq(melcenters);

%compute filter bandwidths (linear scale)
startfreq = [0 , fcenters(1:(nofChannels-1))];
endfreq = [fcenters(2:nofChannels) , fmax];
bandwidth = endfreq - startfreq ;

%quantize into FFT indices
indexcenter = round(fcenters ./df);
%compute resulting frequencies
fftfreq = indexcenter.*df;

%compute start indices of windows
indexstart = [1 , indexcenter(1:nofChannels-1)];
%compute stop indices of windows
indexstop = [indexcenter(2:nofChannels),Nmax];
%compute bandwidth (number of indices per window)
idxbw = (indexstop - indexstart)+1;
%compute bendwidth [Hz]
FFTbandwidth = idxbw.*df;

%compute triangle-shaped filter coefficients
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

n2 = floor(n / 2);
z = W * abs(frame(1:n2, :)).^2;

r = dct(log(z));


