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
parser.on('open', () => {
	console.log('port open completed!!');
});

// 受信割り込み処理
parser.on('data', (data) => {
	console.log('Receive data:', data);

	// 送信処理
	setTimeout(() => {
		const data = 'Hi Tom';

		port.write(data, () => {
			console.log('Send data:', data);
		});
	}, 100);
});
