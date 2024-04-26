% Baca gambar
I = imread('tugas.jpeg'); % Ganti 'gambar.jpg' dengan nama file gambar Anda

% Konversi gambar ke grayscale jika belum dalam format tersebut
if size(I, 3) == 3
    I_gray = rgb2gray(I);
else
    I_gray = I;
end

% Deteksi tepi menggunakan metode Canny
edge_image = edge(I_gray, 'Canny');

edge_image_sobel = edge(I_gray, 'Sobel');

edge_image_prewitt = edge(I_gray, 'Prewitt');

edge_image_roberts = edge(I_gray, 'Roberts');

edge_image_log = edge(I_gray, 'log');

edge_image_canny_low = edge(I_gray, 'Canny', 0.1);
edge_image_canny_high = edge(I_gray, 'Canny', 0.5);

% Tampilkan gambar dalam susunan 2x4
figure;

subplot(2, 4, 1);
imshow(I);
title('Gambar Asli');

subplot(2, 4, 2);
imshow(edge_image);
title('Canny');

subplot(2, 4, 3);
imshow(edge_image_sobel);
title('Sobel');

subplot(2, 4, 4);
imshow(edge_image_prewitt);
title('Prewitt');

subplot(2, 4, 5);
imshow(edge_image_roberts);
title('Roberts');

subplot(2, 4, 6);
imshow(edge_image_log);
title('LoG');

subplot(2, 4, 7);
imshow(edge_image_canny_low);
title('Canny (Low Threshold)');

subplot(2, 4, 8);
imshow(edge_image_canny_high);
title('Canny (High Threshold)');
