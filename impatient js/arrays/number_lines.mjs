export function numberLines(lines) {
    const maxLineNumber = lines.length;
    const maxDigitCount = maxLineNumber.toString().length;
    return lines.map((line, index) => (index + 1).toString().padStart(maxDigitCount, '0') + ': ' + line);
}