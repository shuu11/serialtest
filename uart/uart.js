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

// port open
port.on('open', () => {
	fs.writeFile('./uart/log.txt', 'port open completed!!\n', (err) => {
		if (err) {
			console.log(err);
		}
	});
});

// 受信割り込み処理
parser.on('data', (data) => {
	fs.appendFile('./uart/log.txt', `Receive data:${data}\n`, (err) => {
		if (err) {
			console.log(err);
		}
	});

	// 送信処理
	setTimeout(() => {
		const data = 'Hi Tom';

		port.write(data, () => {
			fs.appendFile('./uart/log.txt', `Send data:${data}\n`, (err) => {
				if (err) {
					console.log(err);
				}
			});
		});
	}, 100);
});
