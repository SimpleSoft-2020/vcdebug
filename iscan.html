<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>scan</title>
    <script src="https://www.simplesoft.vip/js/html5-qrcode.min.js"></script>
	<!-- <script src="http://unpkg.com/html5-qrcode"></script>  -->
    <style>
        button {
            display: block;
            width: 200px;
            margin: 60px;
            outline: none;
            height: 100px;
            line-height: 40px;
            color: #fff;
            background-color: #26a2ff;
            text-align: center;
            border-radius: 4px;
            border: none;
            cursor: pointer;
        }

        #upload-input {
            opacity: 0;
            filter: alpha(opacity=0);
            display: inline-block;
            width: 100%;
            height: 100%;
        }

        #upload-text {
            position: relative;
            bottom: 40px;
            user-select: none;
        }
    </style>
</head>

<body>
    
    
    <div id="reader"></div>
    <h3 id="qr-reader-results"></h3>
    <script>
        
        let html5QrCode = new Html5Qrcode("reader"); 
        let reader = document.getElementById("reader");
        let res = document.getElementById('qr-reader-results');
        let config = { fps: 10, qrbox:  400  }; //扫一扫相关设置
       //相机授权
        function useCamera() {
            reader.style.display = "block";
            res.innerText = "";
            Html5Qrcode.getCameras()
                .then((devices) => {
                    if (devices && devices.length) {
                        let cameraId = "";
                        if (devices.length == 1) {
                            cameraId = devices[0].id; //前置摄像头
                        } else {
                            cameraId = devices[1].id;  //后置摄像头
                        }
                        if (cameraId) {
                            startWithCameraId(cameraId);
                        }
                    } else {
                        startWithoutCameraId();
                    }
                })
                .catch((err) => {
                    console.log("没有获取摄像头设备...");
                });
        }

        //带相机ID扫描
        function startWithCameraId(cameraId) {
            html5QrCode
                .start(
                    { deviceId: { exact: cameraId } },
                    config,
                    onScanSuccess,
                    onScanFailure
                )
                .catch((err) => {
                    console.log("通过摄像头扫码异常....", err);
                });
        }

        //不带相机ID扫描,允许传递约束来代替相机设备 ID
        function startWithoutCameraId() {
            //environment 表示后置摄像头  换成user则表示前置摄像头
            html5QrCode.start(
                { facingMode: "environment" } || {
                    facingMode: { exact: "environment" },
                },
                config,
                onScanSuccess,
                onScanFailure
            );
        }

        
        function onScanSuccess(decodedText, decodedResult) {
            res.innerText = "扫码成功结果:\n" + decodedText;
			html5QrCode.stop();
			reader.style.display = "none";
        }

        
        function onScanFailure(error) {
        }
    </script>

    <button onclick="useCamera()">扫一扫</button>
</body>

</html>