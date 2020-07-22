export function updateProperty(obj, propName, value) {
    return {...obj, [propName]: value }
}