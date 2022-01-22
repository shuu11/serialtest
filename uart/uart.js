const fs = require('fs');
const SerialPort = require('serialport');
const Delimiter = require('@serialport/parser-delimiter');
const ByteLength = require('@serialport/parser-byte-length');
const InterByteTimeout = require('@serialport/parser-inter-byte-timeout');

const port = new SerialPort('COM3', {
	baudRate: 19200,
	dataBits: 8,
	parity: 'none',
	stopBits: 1,
});

const parser = port.pipe(new Delimiter({ delimiter: '\0' })); //	区切り文字の指定
// const parser = port.pipe(new ByteLength({ length: 11 }));	//	受信文字列数の指定
// const parser = port.pipe(new InterByteTimeout({ interval: 30 }));	//	受信時間のタイムアウトの指定

const logColor = {
	yellow: '\x1b[38;2;255;255;50m',
	orange: '\x1b[38;2;255;140;0m',
	reset: '\x1b[0m',
};

const srcPath = {
	fs: './uart/log.txt',
};

// port open
port.on('open', () => {
	const text = 'port open completed!!';

	console.log(text);

	fs.writeFile(srcPath.fs, `${text}\n`, (err) => {
		if (err) {
			console.log(err);
		}
	});
});

// 受信処理
parser.on('data', (data) => {
	const text = `Receive data:`;

	console.log(`${text}${logColor.yellow}${data}${logColor.reset}`);

	fs.appendFile(srcPath.fs, `${text}${data}\n`, (err) => {
		if (err) {
			console.log(err);
		}
	});

	// 送信処理
	setTimeout(() => {
		const text = 'Send data:';
		const data = 'Hi Tom';

		console.log(`${text}${logColor.orange}${data}${logColor.reset}`);

		port.write(data, () => {
			fs.appendFile(srcPath.fs, `${text}${data}\n`, (err) => {
				if (err) {
					console.log(err);
				}
			});
		});
	}, 100);
});
