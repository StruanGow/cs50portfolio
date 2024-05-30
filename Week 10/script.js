let expression = '';
let lastResult = 0;

function appendValue(value) {
  expression += value;
  document.getElementById('result').value = expression;
}

function clearResult() {
  expression = '';
  document.getElementById('result').value = '';
}

function calculate() {
  try {
    lastResult = eval(expression);
    document.getElementById('result').value = lastResult;
    expression = '';
  } catch (error) {
    document.getElementById('result').value = 'Error';
    expression = '';
  }
}

function calculateSin() {
  const result = Math.sin(parseFloat(expression));
  document.getElementById('result').value = result;
}

function calculateCos() {
  const result = Math.cos(parseFloat(expression));
  document.getElementById('result').value = result;
}

function calculateTan() {
  const result = Math.tan(parseFloat(expression));
  document.getElementById('result').value = result;
}

function calculateSqrt() {
  const result = Math.sqrt(parseFloat(expression));
  document.getElementById('result').value = result;
}

function calculateIndices() {
  expression += '**';
  document.getElementById('result').value = expression;
}

function calculateExponential() {
  const result = Math.exp(parseFloat(expression));
  document.getElementById('result').value = result;
}
function useLastResult() {
  expression += lastResult;
  document.getElementById('result').value = expression;
}
function deleteCharacter() {
  expression = expression.slice(0, -1);
  document.getElementById('result').value = expression;
}
document.addEventListener('keydown', function(event) {
  if (event.key >= '0' && event.key <= '9') {
    appendValue(event.key);
  } else if (event.key === '.') {
    appendValue('.');
  } else if (event.key === '+' || event.key === '-' || event.key === '*' || event.key === '/') {
    appendValue(event.key);
  } else if (event.key === '(' || event.key === ')') {
    appendValue(event.key);
  } else if (event.key === 'Enter' || event.key === '=') {
    calculate();
  } else if (event.key === 'Backspace') {
    deleteCharacter();
  }
});
function toggleTheme() {
  const body = document.body;
  body.classList.toggle('dark-theme');
}
