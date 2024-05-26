
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Carduino Control</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f0f0f0;
            text-align: center;
        }
        .container {
            max-width: 600px;
            margin: 0 auto;
            padding: 20px;
            background-color: #ffffff;
            border-radius: 10px;
            box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
        }
        h1 {
            color: #333;
        }
        .speed {
            font-size: 24px;
            margin-bottom: 10px;
        }
        .distance {
            font-size: 18px;
            color: #666;
        }
        .control-buttons {
            margin-top: 20px;
        }
        button {
            background-color: #032345;
            color: #fff;
            border: none;
            padding: 10px 20px;
            font-size: 16px;
            cursor: pointer;
            border-radius: 5px;
        }
        button:hover {
            background-color: #0056b3;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Carduino Control Panel</h1>
        <br>
        
        <div class="control-buttons">
            <form method="post">
                <button type="submit" name="ileri">İleri</button>
                <button type="submit" name="geri">Geri</button>
                <button type="submit" name="sol">Sol</button>
                <button type="submit" name="sag">Sağ</button>
                <button type="submit" name="bos">Boş</button>
            </form>
        </div>
    </div>
    </div>
</body>
</html>

<?php
if(isset($_POST['ileri'])) {
    $dosya = 'index.txt';
    file_put_contents($dosya, "ileri");
}

if(isset($_POST['geri'])) {
    $dosya = 'index.txt';
    file_put_contents($dosya, "geri");;
}

if(isset($_POST['sag'])) {
    $dosya = 'index.txt';
    file_put_contents($dosya, "sag");
}

if(isset($_POST['sol'])) {
    $dosya = 'index.txt';
    file_put_contents($dosya, "sol");
}
if(isset($_POST['bos'])) {
    $dosya = 'index.txt';
    file_put_contents($dosya, "bos");
}
?>
