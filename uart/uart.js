const fs = require('fs');
const SerialPort = require('serialport');
const { Readline } = SerialPort.parsers;

const port = new SerialPort('COM3', {
	baudRate: 19200,
	dataBits: 8,
	parity: 'none',
	stopBits: 1,
});

const parser = port.pipe(new Readline({ delimiter: '\0' }));

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

// 受信割り込み処理
parser.on('data', (data) => {
	const text = `Receive data:`;

	console.log(`${text}${data}`);

	fs.appendFile(srcPath.fs, `${text}${data}\n`, (err) => {
		if (err) {
			console.log(err);
		}
	});

	// 送信処理
	setTimeout(() => {
		const text = 'Send data:'
		const data = 'Hi Tom';

		console.log(`${text}${data}`);

		port.write(data, () => {
			fs.appendFile(srcPath.fs, `${text}${data}\n`, (err) => {
				if (err) {
					console.log(err);
				}
			});
		});
	}, 100);
});
