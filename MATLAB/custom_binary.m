

% Fungsi untuk membuat citra biner dengan nilai threshold yang dapat diatur
function binary_image = custom_binary(image, threshold)
    % Konversi citra ke grayscale jika belum dalam format tersebut
    if size(image, 3) == 3
        image_gray = rgb2gray(image);
    else
        image_gray = image;
    end
    
    % Buat citra biner dengan menggunakan nilai threshold yang diberikan
    binary_image = image_gray > threshold;
end
