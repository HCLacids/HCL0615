export function arrayWithObjectsToTable(data) {
    return `
    <table>
  ${data.map(
    (arr) => `<tr><td>${arr.last}</td><td>${arr.first}</td></tr>`)
    .join('\n  ')}
</table>
    `;
}

export function arrayToUnorderedListWithEscaping(data){
    return `
    <ul>
${data.map(item => `  <li>${escapeHtml(item)}</li>`).join('\n')}
</ul>
    `;
}

function escapeHtml(str){
    return str.replace(/&/g, '&amp;')
              .replace(/>/g, '&gt;')
              .replace(/</g, '&lt;')
              .replace(/"/g, '&quot;')
              .replace(/'/g, '&#39;')
              .replace(/`/g, '&#96;');
}