const SerialPort = require('serialport');
const Delimiter = require('@serialport/parser-delimiter');
const { Readline } = SerialPort.parsers;

const port = new SerialPort('COM3', {
	baudRate: 9600,
	dataBits: 8,
	parity: 'none',
	stopBits: 1,
	flowControl: false,
});
const parser = port.pipe(new Readline({ delimiter: '\0' }));

// port open
parser.on('open', () => {
	console.log('port open completed!!');
});

// 受信割り込み処理
parser.on('data', (data) => {
	console.log(data);

	// 送信割り込み処理
	setTimeout(() => {
		port.write('Hi Tom', () => {
			console.log('message written');
		});
	}, 100);
});
