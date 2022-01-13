const SerialPort = require('serialport');
const Delimiter = require('@serialport/parser-delimiter')

const port = new SerialPort('COM3', { baudRate: 9600 });
const parser = port.pipe(new Delimiter({ delimiter: '\0' }))

// port open
parser.on('open', () => {
	console.log('port open completed!!');
});

// 受信割り込み処理
parser.on('data', (data) => {
	const text = String(data);
	console.log(text);
});
