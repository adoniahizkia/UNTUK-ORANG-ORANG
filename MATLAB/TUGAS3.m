image = imread('tugas.jpeg'); % Ganti 'gambar.jpg' dengan nama file gambar Anda
threshold = 10; % Ganti nilai threshold sesuai kebutuhan
binary_image = custom_binary(image, threshold);

% Tampilkan citra asli dan citra biner
figure;
subplot(1, 2, 1);
imshow(image);
title('Citra Asli');
subplot(1, 2, 2);
imshow(binary_image);
title('Citra Biner');
